package com.Heap;

import java.util.Arrays;

import static com.sun.tools.javac.jvm.ByteCodes.swap;

public class Heap2 {

    public static void main(String[] args) {

         var heap2=new Heap2();
         heap2.add(10);
        heap2.display();
        heap2.add(20);
        heap2.display();
        heap2.add(30);
        heap2.display();
        heap2.add(40);
        heap2.display();
        heap2.add(5);
        heap2.display();

    }
   int []heap=new int[10];

    int size=0;
    public void add(int item){

        heap[size++]=item;
        upHeapify(size-1);
    }

    private void upHeapify(int childIndex) {
        int parentIndex=(childIndex-1)/2;
        if (heap[childIndex]<heap[parentIndex]){
            swap(parentIndex,childIndex);
            upHeapify(parentIndex);
        }

    }

    private void swap(int parentIndex, int childIndex) {
        int ith=heap[parentIndex];
        int jth=heap[childIndex];

        heap[parentIndex]=jth;
        heap[childIndex]=ith;


    }
int remove=0;
    public int remove(){
        swap(0,heap.length-1);
        int remove =0;
        for (int i = 0; i <heap.length ; i++) {
               if (i==heap.length){
                   remove=heap[i];
                   heap[i]=0;
               }
        }
        downheapify(0);
      return remove;
    }

    private void downheapify(int parentIndex) {
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        int minIdx=parentIndex;

        if (heap[leftChildIndex]<heap[minIdx]){
            minIdx=leftChildIndex;
        }

        if (heap[rightChildIndex]<heap[minIdx]){
            minIdx=rightChildIndex;
        }
        if (minIdx!=parentIndex){
            swap(minIdx,parentIndex);
            downheapify(minIdx);
        }


    }

    public void display(){
        System.out.println(Arrays.toString(heap));
    }


}
