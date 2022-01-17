arr=[1,2,3,100,0,5,200,50]

def selection(arr):
    for i in range(0,len(arr)-1):
        smallest=i
        for j in range(i+1,len(arr)):
            if(arr[j]<arr[smallest]):
                smallest=j

        arr[i],arr[smallest]=arr[smallest],arr[i]

    print(arr)

selection(arr)



            