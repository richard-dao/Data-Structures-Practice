//Java
public class HeapNode {
    int value;
    HeapNode left;
    HeapNode right;
    public HeapNode(int value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
    
}
import java.util.Arrays;

public class MinHeap {
    int size;
    int maxSize;
    int[] heap;
    public MinHeap(int max){
        this.maxSize = max;
        heap = new int[max];
        size = 0; 
    }
    // Helper Methods
    public int getLeftChildIndex(int parentIndex){
        return (2 * parentIndex) + 1;
    }
    public int getRightChildIndex(int parentIndex){
        return (2 * parentIndex) + 2;
    }
    public int getParentIndex(int childIndex){
        return (childIndex - 1)/2;
    }

    public boolean hasLeftChild(int index){
        if (getLeftChildIndex(index) > size){
            return false;
        }
        return true;
    }
    public boolean hasRightChild(int index){
        if (getRightChildIndex(index) > size){
            return false;
        }
        return true;
    }
    public boolean hasParent(int index){
        if (index > size || index == 0){
            return false;
        }
        return true;
    }

    public int leftChild(int index){
        return heap[getLeftChildIndex(index)];
    }
    public int rightChild(int index){
        return heap[getRightChildIndex(index)];
    }
    public int parent(int index){
        return heap[getParentIndex(index)];
    }
    
    public void expandArr(){
        if (size == maxSize){
            heap = Arrays.copyOf(heap, maxSize*2);
            maxSize = maxSize * 2;
        }
    }
    public boolean isEmpty(){
        return size == 0;
    }

    public int peek(){
        if (isEmpty()){
            throw new IllegalStateException();
        }
        return heap[0];
    }

    public int poll(){
        if (isEmpty()){
            throw new IllegalStateException();
        }
        int temp = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapifyDown();
        return temp;

    }

    public void add(int value){
        expandArr();
        heap[size] = value;
        size++;
        heapifyUp();
    }

    public void heapifyDown(){
        int i = 0;
        while (hasLeftChild(i)){
            int smallestIndex = getLeftChildIndex(i);
            if (hasRightChild(i) && (rightChild(i) < leftChild(i))){
                smallestIndex = getRightChildIndex(i);
            }
            if (heap[i] < heap[smallestIndex]){
                return;
            }
            else{
                swap(i, smallestIndex);
            }
            i = smallestIndex;
        }
    }
    
    public void heapifyUp(){
        int i = size-1;
        while(hasParent(i)){
            if (parent(i) > heap[i]){
                swap(getParentIndex(i), i);
            }
            else{
                return;
            }
            i = getParentIndex(i);
        }
    }
    
    public void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    public void display(){
        System.out.print("[");
        for (int i = 0; i < size; i++){
            System.out.print(heap[i]);
            if (i != size-1){
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public int[] getHeap(){
        int[] rArr = new int[size];
        for (int i = 0; i < size; i++){
            rArr[i] = heap[i];
        }
        return rArr;
    }

    public int height(){
        return 1 + (int) (Math.log(size) / Math.log(2));
    }
}
public class MinHeapTree {
    HeapNode root;
    public MinHeapTree(){
        root = null;
    }

    public HeapNode convertArrToTree(int[] heap, HeapNode current, int i){
        if (i < heap.length){
            HeapNode temp = new HeapNode(heap[i]);
            current = temp;
            
            current.left = convertArrToTree(heap, current.left, 2 * i + 1);
            current.right = convertArrToTree(heap, current.right, 2 * i + 2);
        }
        return current;
    }

    public void printInOrder(HeapNode current){
        if (current == null){
            return;
        }
        printInOrder(current.left);
        System.out.print(current.value + ", ");
        printInOrder(current.right);
    }
    public void printLevelOrder(int height){
        int i;
        System.out.print("[ ");
        for (i = 0; i <= height; i++){
            printLevel(root, i);
        }
        System.out.println("]");
        
    }

    public void printLevel(HeapNode current, int level){
        if (current == null){
            return;
        }
        if (level == 1){
            System.out.print(current.value + " ");
            
        }
        else if (level > 1){
            printLevel(current.left, level-1);
            printLevel(current.right, level-1);
        }

    }

}
import java.util.ArrayList;

public class main{
    public static void main(String[] args){
        MinHeap h = new MinHeap(10);
        h.add(0);
        h.add(1);
        h.add(2);
        h.add(3);
        h.add(4);
        h.add(5);
        h.add(6);
        h.add(7);
        System.out.println(h.poll());
        h.display();
        System.out.println(h.height());
        MinHeapTree mT = new MinHeapTree();
        mT.root = mT.convertArrToTree(h.getHeap(), mT.root, 0);
        mT.printLevelOrder(h.height());

    }
}
