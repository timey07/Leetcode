/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    let n= prices.length;
    // let dp= Array.from({length:n}, ()=> Array(2).fill(-1));
    let curr = Array(2).fill(0);
    let next = Array(2).fill(0);
    let next2= Array(2).fill(0);
    
    for(let i=n-1;i>=0;--i){
        let notTake= next[1];
        let take= -prices[i]+next[0];
        curr[1]=Math.max(notTake,take);

        notTake= next[0];
        take= prices[i]+next2[1];
        curr[0]=Math.max(notTake,take);
        
        [next2,next,curr]=[next,curr,next2];
    }
    return next[1];
};
