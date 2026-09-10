/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let mini= Infinity;
    let ans=0;
    let n= prices.length;
    for(let i=0; i<n; ++i){
        mini=Math.min(prices[i],mini);
        ans=Math.max(ans,prices[i]-mini);
    }
    return ans;
};
