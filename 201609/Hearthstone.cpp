#include<bits/stdc++.h>
using namespace std;

typedef struct{
	int healthVal, attackVal;
}Follower;

int main(){
	int number;
	string option;
	int role1 = 30, role2 = 30;
	int *currentRole = &role1, *anotherRole = &role2;
	vector<Follower> followerList1, followerList2;
	vector<Follower> *currentList = &followerList1, *anotherList = &followerList2;
	int opNum1, opNum2;
	Follower tempFollower;
	cin>>number;
	while(number--){
		cin>>option;
		if(option == "summon"){
			cin>>opNum1>>tempFollower.attackVal>>tempFollower.healthVal;
			currentList->insert(currentList->begin() + opNum1 - 1, tempFollower);
		}else if(option == "attack"){
			cin>>opNum1>>opNum2;
			if(opNum2 == 0)
				*anotherRole -= (*currentList)[opNum1 - 1].attackVal;
			else{
				Follower attackFollower = (*currentList)[opNum1 - 1], defenceFollower = (*anotherList)[opNum2 - 1];
				attackFollower.healthVal -= defenceFollower.attackVal;
				defenceFollower.healthVal -= attackFollower.attackVal;
				currentList->erase(currentList->begin() + opNum1 - 1);
				anotherList->erase(anotherList->begin() + opNum2 - 1);
				if(attackFollower.healthVal > 0)
					currentList->insert(currentList->begin() + opNum1 - 1, attackFollower);
				if(defenceFollower.healthVal > 0)
					anotherList->insert(anotherList->begin() + opNum2 - 1, defenceFollower);
			}
		}else if(option == "end"){
			vector<Follower> *temp = currentList;
			currentList = anotherList;
			anotherList = temp;
			int *tempRole = currentRole;
			currentRole = anotherRole;
			anotherRole = tempRole;
		}
		/*cout<<endl<<"role 1 :"<<endl;
		for(int i = 0; i < followerList1.size(); i++)
			cout<<"attack "<<followerList1[i].attackVal<<" health "<<followerList1[i].healthVal<<endl;
		cout<<endl<<"role 2 :"<<endl;
		for(int i = 0; i < followerList2.size(); i++)
			cout<<"attack "<<followerList2[i].attackVal<<" health "<<followerList2[i].healthVal<<endl;
        cout<<endl;*/
	}
	if(role1 <= 0)
		cout<<"-1"<<endl;
	else if(role2 <= 0)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	cout<<role1<<endl;
	cout<<followerList1.size();
	for(int i = 0; i < followerList1.size(); i++)
		cout<<" "<<followerList1[i].healthVal;
	cout<<endl;
	cout<<role2<<endl;
	cout<<followerList2.size();
	for(int i = 0; i < followerList2.size(); i++)
		cout<<" "<<followerList2[i].healthVal;
	cout<<endl;
	return 0;
}
