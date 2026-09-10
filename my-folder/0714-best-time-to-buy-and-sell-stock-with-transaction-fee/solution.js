/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {
    let n= prices.length;
    let curr = Array(2).fill(0);
    let next = Array(2).fill(0);
    
    for(let i=n-1;i>=0;--i){
        let notTake= next[1];
        let take= -prices[i]+next[0];
        curr[1]=Math.max(notTake,take);

        notTake= next[0];
        take= prices[i]+next[1]-fee;
        curr[0]=Math.max(notTake,take);
        
        [next,curr]=[curr,next];
    }
    return next[1];
};
