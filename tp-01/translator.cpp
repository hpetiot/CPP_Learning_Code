#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool parse_params(const int argc, char** argv, string& dict_path, string& word, string& translation,
                  vector<string>& sentence);
vector<pair<string, string>> open_dictionary(const string& path);
void                         save_dictionary(const string& path, const vector<pair<string, string>>& dict);
void translate(const vector<string>& sentence, const vector<pair<string, string>>& dict);

int main(int argc, char* argv[]) {
    string         dict_path, word, translation;
    vector<string> sentence;

    if (!parse_params(argc, argv, dict_path, word, translation, sentence))
    { return -1; }

    vector<pair<string, string>> dict;

    if (!dict_path.empty())
    { dict = open_dictionary(dict_path); }

    if (!word.empty() && !translation.empty())
    {
        dict.emplace_back(word, translation);

        if (!dict_path.empty())
        { save_dictionary(dict_path, dict); }
    }

    if (!sentence.empty())
    { translate(sentence, dict); }

    return 0;
}

bool parse_params(const int argc, char** argv, string& dict_path, string& word, string& translation,
                  vector<string>& sentence) {
    for (auto i = 1; i < argc; ++i)
    {
        std::string option = argv[i];

        if (option == "-d" && (i + 1) < argc)
        { dict_path = argv[++i]; }
        else if (option == "-a" && (i + 2) < argc)
        {
            word        = argv[++i];
            translation = argv[++i];
        }
        else
        { sentence.emplace_back(argv[i]); }
    }

    if (dict_path.empty())
    {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }
    // debugg
    /*cout << "dict_path = " << dict_path << '\n';
    cout << "word = " << word << '\n';
    cout << "translation = " << translation << '\n';
    cout << "sentence = " << '[' << '\n';
    for (auto elem : sentence)
    { cout << '\t' << elem << '\n'; }
    cout << ']' << endl;*/
    return true;
}

vector<pair<string, string>> open_dictionary(const string& path) {
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    if (!file)
    {
        // debug
        cerr << "Couln't find \'" << path << "\' file" << endl;
        for (auto elem : dict)
        { cout << '\'' << elem.first << "\' \'" << elem.second << '\'' << endl; }
        return dict;
    }

    while (!file.eof())
    {
        // debugg
        // cout << "open_dir -> loop" << endl;

        string word;
        file >> word;
        // debug
        // cout << "world = \'" << word << '\'' << endl;

        string translation;
        file >> translation;
        // debug
        // cout << "translation = \'" << translation << '\'' << endl;

        dict.emplace_back(pair { word, translation });
    }
    dict.pop_back(); /* as the 'read a word' opperationt skips whites, when there is a dictioinary, it will
    read all line and stops right at the end of the last word. This mean that there is still a '\n' between
    the cursor and EOF. Thus when reading in a loop, it will attempt a fnal read that will then skipp this
    last white and be unable to read any thing. Meaning the last read is always 2 strings = "". That gets
    stored in the dictionary and then printet out in the save file. This line avoids that behaviour by
    destoying the "" "" trailing lin ein the dictionary.
    */

    // debugg
    // for (auto elem : dict)
    //{ cout << '\'' << elem.first << "\' \'" << elem.second << '\'' << endl; }

    return dict;
}

void save_dictionary(const string& path, const vector<pair<string, string>>& dict) {
    fstream file { path, ios_base::out };

    for (auto word_translation : dict)
    { file << word_translation.first << " " << word_translation.second << std::endl; }
}

void translate(const vector<string>& sentence, const vector<pair<string, string>>& dict) {
    for (auto word : sentence)
    {
        for (auto word_translation : dict)
        {
            if (word == word_translation.first)
            { cout << word_translation.second << " "; }
            else
            {
                cout << "???"
                     << " ";
            }
        }
    }
}
