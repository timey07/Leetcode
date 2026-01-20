class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        if(n==0) return true;
        if(s==1 && flowerbed[0]==0) return true;
        if(s==1 && flowerbed[0]==1) return false;
        if(flowerbed[1]==0 && flowerbed[0]==0){
            flowerbed[0]=1;
            n--;
        }
        if(n==0) return true;
        if(flowerbed[s-2]==0 && flowerbed[s-1]==0){
            flowerbed[s-1]=1;
            n--;
        }
        if(n==0) return true;
        for(int i=1;i<s-1;++i){
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                n--;
                flowerbed[i]=1;
            }
            if(n==0) break;
        } 
        if(n) return false;
        else return true;
    }
};
