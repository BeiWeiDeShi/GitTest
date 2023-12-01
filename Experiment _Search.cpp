<<<<<<< HEAD
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int Sequential_Search(int a[],int n,int key){//普通顺序查找
    int i;
    for(i=0; i<n; i++)
        if(a[i]==key)return i+1;
    return -1;
}

int Sequential_Search2(int a[],int length,int value){
//优化顺序查找，将数组最后一个设为"哨兵",这样就不用判断越界了
//(也可以将哨兵设在数组开头的位置)
    int i=0;
    a[length]=value;
    while(a[i]!=value)
        i++;
    if(i==length)return -1;
    else return i+1;
}

int binarySearch(int a[],int n,int key){//二分查找
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>key)high=mid-1;
        else if(a[mid]<key)low=mid+1;
        else return mid;
    }
    return -1;
}

int binarySearch2(int a[], int length, int value){
    int low=0, high=value-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] < value)
            low = mid+1;
        else if(a[mid] > value)
            high = mid-1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int length;
    cout << "please enter the length of the array:\n";
    cin >> length;
    int *a = new int[length];
    cout << "please enter the value of the array\n";
    for(int i=0; i<length; i++)
        cin >> a[i];
    cout << "\n-----------------\n";

    cout << "please enter the value you want to find:\n";
    int value;
    cin >> value;            cout << "\n-----------------\n";

    cout <<"Sequential_Search:\n";
    cout << "the position of the value you find: " 
    << Sequential_Search(a,length,value);
    cout << "\n\n-----------------\n";


    cout <<"Optimize_Sequential_Search:\n";
    cout << "the position of the value you find: " 
    << Sequential_Search2(a,length,value);
    cout << "\n\n-----------------\n";

    cout <<"Binary_Search:\n-----------------\n";
    sort(a,a+length);
    cout <<"the arry in order\n-----------------\n";
    for(int i=0; i<length; i++)printf("%d ",a[i]);
    cout <<"\n-----------------\n";
    printf("%d\n",binarySearch(a,length,value)+1);

    return 0;
=======
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int Sequential_Search(int a[],int n,int key){//普通顺序查找
    int i;
    for(i=0; i<n; i++)
        if(a[i]==key)return i+1;
    return -1;
}

int Sequential_Search2(int a[],int length,int value){
//优化顺序查找，将数组最后一个设为"哨兵",这样就不用判断越界了
//(也可以将哨兵设在数组开头的位置)
    int i=0;
    a[length]=value;
    while(a[i]!=value)
        i++;
    if(i==length)return -1;
    else return i+1;
}

int binarySearch(int a[],int n,int key){//二分查找
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>key)high=mid-1;
        else if(a[mid]<key)low=mid+1;
        else return mid;
    }
    return -1;
}

int binarySearch2(int a[], int length, int value){
    int low=0, high=value-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] < value)
            low = mid+1;
        else if(a[mid] > value)
            high = mid-1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int length;
    cout << "please enter the length of the array:\n";
    cin >> length;
    int *a = new int[length];
    cout << "please enter the value of the array\n";
    for(int i=0; i<length; i++)
        cin >> a[i];
    cout << "\n-----------------\n";

    cout << "please enter the value you want to find:\n";
    int value;
    cin >> value;            cout << "\n-----------------\n";

    cout <<"Sequential_Search:\n";
    cout << "the position of the value you find: " 
    << Sequential_Search(a,length,value);
    cout << "\n\n-----------------\n";


    cout <<"Optimize_Sequential_Search:\n";
    cout << "the position of the value you find: " 
    << Sequential_Search2(a,length,value);
    cout << "\n\n-----------------\n";

    cout <<"Binary_Search:\n-----------------\n";
    sort(a,a+length);
    cout <<"the arry in order\n-----------------\n";
    for(int i=0; i<length; i++)printf("%d ",a[i]);
    cout <<"\n-----------------\n";
    printf("%d\n",binarySearch(a,length,value)+1);

    return 0;
>>>>>>> c
}