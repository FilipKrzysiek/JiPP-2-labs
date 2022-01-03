//
// Created by filip on 03.01.2022.
//

#ifndef SYF_CSVLIB_H
#define SYF_CSVLIB_H

class CsvLib {
private:
    fstream stream;
    bool haveHeaderRow;
    vector<string> headers;
    char delimiter;

public:
    CsvLib(string path, char delimiter = ',', bool haveHeaderRow = true);

    map<string, string> getRow();
    //vector<string>
    bool hasNextRow();

    ~CsvLib();
};

#endif //SYF_CSVLIB_H
