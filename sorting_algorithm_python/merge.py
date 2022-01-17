arr=[100,50,200,400,300,700,800,1]

def sort(arr,l,mid,u):
    size1=mid-l+1
    size2=u-mid
    L_sub_arr=[]
    R_sub_arr=[]

    for i in range(0,size1):
        L_sub_arr.append(arr[i+l])
        
    print(L_sub_arr)
    for i in range(0,size2):
        R_sub_arr.append(arr[i+mid+1])
    print(R_sub_arr)
    i=0
    j=0
    k=l
    while(i<size1 and j<size2):
        if(R_sub_arr[j]<L_sub_arr[i]):
            arr[k]=R_sub_arr[j]
            j+=1
            k+=1
        else:
            arr[k]=L_sub_arr[i]
            i+=1
            k+=1

    while(j<size2):
        arr[k]=R_sub_arr[j]
        j+=1
        k+=1
    while(i<size1):
        arr[k]=L_sub_arr[i]
        i+=1
        k+=1

def mergesort(arr,l,u):
    if(l<u):
        mid=int((l+u)/2)
        mergesort(arr,l,mid)
        mergesort(arr,mid+1,u)
        sort(arr,l,mid,u)


mergesort(arr,0,len(arr)-1)

print("The sorted array using merge sort is:\n",arr)