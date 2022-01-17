from cmath import pi


arr=[3,4,2,5,9,8,6,1,7]

def partition(arr,l,h):
    i=l-1
    pivot=arr[h]
    for j in range(l,h):
        if(arr[j]<=pivot):
            i=i+1
            arr[i],arr[j]=arr[j],arr[i]
    arr[i+1],arr[h]=arr[h],arr[i+1]
    return i+1

def quick(arr,l,h):
    if(l<h):
        index_partition=partition(arr,l,h)
        print(index_partition)
        quick(arr,l,index_partition-1)
        quick(arr,index_partition+1,h)


quick(arr,0,len(arr)-1)

print("The sorted data is\n",arr)