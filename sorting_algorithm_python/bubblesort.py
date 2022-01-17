arr=[2,3,4,6,7,1,8,9,10,100,400,50,70,]

def bubblesort(arr):
    for i in range(0,len(arr)-1):
        swap=False
        for j in range(0,len(arr)-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
                swap=True
        if(swap==False):
            break

    print(arr)

bubblesort(arr)