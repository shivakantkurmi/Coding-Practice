//find median of two sorted array 
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArraysUsingMergeSort(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    vector<int> merged(n+m);
    merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),merged.begin());
    if((n+m)%2==0){
        return (merged[(n+m)/2]+merged[(n+m)/2-1])/2.0;
    }
    else{
        return merged[(n+m)/2];
    }
}

double findMedianSortedArraysUsingTwoPointer(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    int i=0,j=0;
    int counter=0;
    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
        counter++;
        if(counter==(n+m)/2){
            if((n+m)%2==0){
                if(i<n && j<m){
                    return (min(nums1[i],nums2[j])+max(nums1[i-1],nums2[j-1]))/2.0;
                }
                else if(i<n){
                    return (nums1[i]+nums1[i-1])/2.0;
                }
                else{
                    return (nums2[j]+nums2[j-1])/2.0;
                }
            }
            else{
                if(i<n && j<m){
                    return min(nums1[i],nums2[j]);
                }
                else if(i<n){
                    return nums1[i];
                }
                else{
                    return nums2[j];
                }
            }
            return 0;
        }
    }
    while(i<n){//if we reach here then it means we have traversed all elements of nums2 and still not reached the median so we will traverse nums1
        counter++;
        if(counter==(n+m)/2){
            if((n+m)%2==0){
                return (nums1[i]+nums1[i-1])/2.0;
            }
            else{
                return nums1[i];
            }
            return 0;
        }
        i++;
    }
    while(j<m){//if we reach here then it means we have traversed all elements of nums1 and still not reached the median so we will traverse nums2
        counter++;
        if(counter==(n+m)/2){
            if((n+m)%2==0){
                return (nums2[j]+nums2[j-1])/2.0;
            }
            else{
                return nums2[j];
            }
            return 0;
        }
        j++;
    }
}

double findMedianSortedArraysUsingBinarySearch(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    if(n>m){
        return findMedianSortedArraysUsingBinarySearch(nums2,nums1);
    }
    int low=0,high=n;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=(n+m+1)/2-mid1;

        int l1=(mid1==0)?INT_MIN:nums1[mid1-1];
        int l2=(mid2==0)?INT_MIN:nums2[mid2-1];
        int r1=(mid1==n)?INT_MAX:nums1[mid1];
        int r2=(mid2==m)?INT_MAX:nums2[mid2];

        if(l1<=r2 && l2<=r1){ //if we have found the correct partition
            if((n+m)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else{
                return max(l1,l2);
            }
        }
        else if(l1>r2){ //if l1 is greater than r2 then we need to move towards left in nums1
            high=mid1-1;
        }
        else{  //if l2 is greater than r1 then we need to move towards right in nums1
            low=mid1+1;
        }
    }
    return 0.0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    //taking input of a and b 
    for(int &i:a)cin>>i;
    for(int &i:b)cin>>i;

    //way 1 : using merge and sort
    cout<<"Using Merge Sort: "<<findMedianSortedArraysUsingMergeSort(a,b)<<endl;


    //way 2 using two pointer approach
    cout<<"Using Two Pointer: "<<findMedianSortedArraysUsingTwoPointer(a,b)<<endl;

    //binary search approach
    cout<<"Using Binary Search: "<<findMedianSortedArraysUsingBinarySearch(a,b)<<endl;



}
