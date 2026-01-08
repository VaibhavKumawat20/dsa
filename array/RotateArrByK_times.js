// //Rotate array by K times
// // let arr = [1, 2, 3, 4, 5];
// // Required arr = [3, 4, 5, 1, 2];
// //Rotate an Array K times ie.. k = 7  {TC = O(n), SC = O(n)}
// // 1 2 3 4 5    k-n = 2
// // 2 3 4 5 1
// // 3 4 5 1 2
// let arr = [ 1,2,3,4,5];
// let k = 12
// let n = arr.length
// let d = k%n
// console.log(d)
// let temp=[],count = 0;
// for(let i=d;i<n;i++) {
//     temp[count++] = arr[i]
// }
// for(let i=0;i<d;i++) {
//     temp[count++] = arr[i]
// }
// console.log(temp)

// TC = O(n), SC = O(1)
function reverse(arr, st, end){
    while(st<=end){
        let temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++; end--;
    }
}
let arr = [1, 2, 3, 4, 5];
let k = 2;
let n = arr.length;
// Required arr = [3, 4, 5, 1, 2];

let st = 0, end = n-1;
reverse(arr, 0, k-1);
reverse(arr, k, n-1);
reverse(arr, 0, n-1);
console.log(arr);