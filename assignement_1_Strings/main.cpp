//Mahmoud El-imbabi//
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

#define Music   0
#define Image   1
#define Movie   2
#define Other   3



int SizeDetector(string s);
int ExtensionDetector(string s);

int main(void)
{
    int NumTestConditions = 0;
    int * NumTestCase = NULL;
    string Input_Line = "";
    int Size = 0;
    int Extension = Other;
    int Result[4]={0};
    cin>>NumTestConditions;
    NumTestCase = new int[NumTestConditions]{0};
    for(int i = 0 ; i < NumTestConditions ; i++)
    {
        cin>>NumTestCase[i];
    }

    for(int i = 0 ; i < NumTestConditions ; i++)
    {

        memset(Result,0,sizeof(Result));   
        for(int j = 0; j <NumTestCase[i] ; j++)
        {
            //dragons_Song .mp3 11b
            getline(cin>>ws,Input_Line);
            Size = SizeDetector(Input_Line);
            Extension = ExtensionDetector(Input_Line);
            Result[Extension]+=Size;
        }
        cout<<"music "<<Result[Music]<<"b images "<<Result[Image]<<"b movies "<<Result[Movie]<<"b other "<<Result[Other]<<"b"<<endl;
    }
          //music 1011b images 0b movies 0b other 5b


    return 0;
}


int SizeDetector(string s)
{
    string temp = "";
    int Size = 0;
    stringstream ss(s); // dragons_Song .mp3 11b
    while(ss>>temp);
    stringstream ss1(temp); // dragons_Song .mp3 11b
    ss1>>Size;//11
    //another method stoi()
    return Size; //11b
}


int ExtensionDetector(string s)
{
    int Extension = Other;
    if(regex_match(s,regex(".*(flac|mp3|aac)\\s\\d+b")))
    {
        Extension = Music;
    }
    else if(regex_match(s,regex(".*(jpg|bmp|gif)\\s\\d+b")))
    {
        Extension = Image;
    }
    else if(regex_match(s,regex(".*(mp4|avi|mkv)\\s\\d+b")))
    {
        Extension = Movie;
    }

    return Extension;

}