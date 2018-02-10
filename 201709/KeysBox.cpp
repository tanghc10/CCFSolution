#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class event{
public:
    int keyIndex;
    int time;
    bool isStart;
};

vector<event> eventList;

bool comp(const event &a, const event &b){
    if (a.time != b.time)
        return a.time < b.time;
    else if(a.isStart != b.isStart)
        return a.isStart < b.isStart;
    else
        return a.keyIndex < b.keyIndex;
}

int main(){
    int keyNumber = 0, eventNumber = 0;
    int eventCnt = 0, keyCnt = 0;
    int tempKey = 0, tempStart = 0, tempDuration = 0;
    event tempEvent;
    cin>>keyNumber>>eventNumber;
    int *keyBox = new int[keyNumber+1];
    for(; keyCnt <= keyNumber; keyCnt++)
        keyBox[keyCnt] = keyCnt;
    for(; eventCnt < eventNumber; eventCnt++){
        cin>>tempKey>>tempStart>>tempDuration;
        tempEvent.keyIndex = tempKey;
        tempEvent.time = tempStart;
        tempEvent.isStart = true;
        eventList.push_back(tempEvent);
        tempEvent.time += tempDuration;
        tempEvent.isStart = false;
        eventList.push_back(tempEvent);
    }
    sort(eventList.begin(), eventList.end(), comp);
    for(eventCnt = 0; eventCnt < eventList.size(); eventCnt++){
        if(eventList[eventCnt].isStart == true){
            for(keyCnt = 1; keyCnt <= keyNumber; keyCnt++){
                if(keyBox[keyCnt] == eventList[eventCnt].keyIndex){
                    keyBox[keyCnt] = -1;
                    break;
                }
            }
        }else{
            for(keyCnt = 1; keyCnt <= keyNumber; keyCnt++){
                if(keyBox[keyCnt] == -1){
                    keyBox[keyCnt] = eventList[eventCnt].keyIndex;
                    break;
                }
            }
        }
    }
    for(keyCnt = 1; keyCnt < keyNumber; keyCnt++)
        cout<<keyBox[keyCnt]<<" ";
    cout<<keyBox[keyCnt]<<endl;
    return 0;
}
