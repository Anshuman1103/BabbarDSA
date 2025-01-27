int mid = s +(e-s)/2;

    if(arr[mid] == k) return true;

    if(arr[mid] > k) return binarySearch(arr, s, mid-1, k);
    
    else return binarySearch(arr, mid+1, e, k);