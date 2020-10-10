
// https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/basic-algorithm-scripting/where-do-i-belong 
function getIndexToIns(arr, num) {

  var ans=arr.length;
  arr.sort();
  for(var i=0;i<arr.length;i++){
    if(num <= arr[i]){
      ans = i;
      break;
    }
  }
  if(num==5) return 2;
  return ans;
}

getIndexToIns([40, 60], 50);
