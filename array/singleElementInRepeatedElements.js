// REQUIRED T.C. = O(LOG N)
// REQUIRED S.C. = O(1)
// ARRAY WITH ALL ELEMENTS REPEATING TWICE BUT A SINGLE ELEMENT ONLY OCCURING ONCE. FIND THAT ELEMENT

let arr = [1, 1, 3, 3, 7, 7, 2, 2, 8, 8, 9, 4, 4];
let n = arr.length;
let st = 0; let end = n-1;
while(st<=end){
    let mid = Math.floor(st + (end-st)/2);
    if(arr[mid]===arr[mid+1] && mid%2!==0){
        end = mid-1;
    }
    else if(arr[mid]===arr[mid-1] && mid%2===0){
        end = mid-1;
    }
    else{
        st = mid+1;
    }
}
console.log(arr[end]);