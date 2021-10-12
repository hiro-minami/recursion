#include <iostream>
#include <map> 
using namespace std;

class Files {
    public:
        string fileName;
        string fileExtension;
        string content;
        bool locked;
        string parentFolder;

        Files(string fileName, string fileExtension, string content, bool locked, string parentFolder) {
            this->fileName = fileName;
            this->fileExtension = (this->isFileExtensionWithinExpectations(fileExtension)) ? fileExtension : ".txt";
            this->content = content;
            this->locked = locked;
            this->parentFolder = parentFolder;
        }

        bool isFileExtensionWithinExpectations(string fileExtension) {
            return fileExtension == ".word"
                || fileExtension == ".png"
                || fileExtension == ".js"
                || fileExtension == ".css"
                || fileExtension == ".html"
                || fileExtension == ".mp4"
                || fileExtension == ".mp3"
                || fileExtension == ".pdf";
        }

        string getLifetimeBandwidthSize() {
            return to_string(this->content.length() * 10) + "MB";
        }
        string getFileType() {
            if (this->fileExtension == ".pdf" || this->fileExtension == ".word" || this->fileExtension == ".txt") return "document";
            else if (this->fileExtension == ".js" || this->fileExtension == ".css" || this->fileExtension == ".html") return "source-code";
            else if (this->fileExtension == ".mp4") return "video";
            else if (this->fileExtension == ".mp3") return "music";
            else return "You syould type correct file extention...";
        }
        string prependContent(string data) {
            if (this->locked == false) {
                this->content = data + this->content;
                return this->content;
            } else {
                cout << "This file is locked. So you can't write content..." << endl;
                return this->content;
            }
        }
        string appendContent(string data) {
            if (this->locked == false) {
                this->content = this->content + data;
                return this->content;
            } else {
                cout << "This file is locked. So you can't write content..." << endl;
                return this->content;
            }    
        }
        string addContent(string data, int position) {
            if (this->locked == false) {
                this->content = this->content.substr(0, position) + data + this->content.substr(position);
                return this->content;
            } else {
                cout << "This file is locked. So you can't write content..." << endl;
                return this->content;
            }
             
        }
        string showFileLocation() {
            return this->parentFolder + " > " + this->fileName + this->fileExtension;
        }
};

int main() {
    Files assignment("assignment", ".word", "Something that occurs too early before preparations are ready. Starting too soon.", false, "homework");
    cout << assignment.getLifetimeBandwidthSize() << endl;
    cout << assignment.prependContent("good morning ") << endl;
    cout << assignment.appendContent(" good evening") << endl;
    cout << assignment.addContent("hello world ", 13) << endl;
    cout << assignment.showFileLocation() << endl;

    return 0;
}