/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length(),left,right,mid,peak=0;
        left=0,right=n-1;
        while(left<right){
            mid=(left+right)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) left=peak=mid+1;
            else right=mid;
        }
        left=0,right=peak;
        while(left<=right){
            mid=left+(right-left)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) left=mid+1;
            else right=mid-1;
        }
        left=peak,right=n-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};