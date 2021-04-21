package Step14_Sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class N06_Q11650 {
	// ������ �ٽ��غ�����!!
    public static void main(String[] args) throws IOException {
    	System.out.println("�ٽ��غ���!");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        ArrayList<int[]> input = new ArrayList<int[]>();// ��ǥ ���� ArrayList
        int[] temp = new int[1];
        for (int i = 0; i < N; i++) { // x��ǥ�� y��ǥ�� arrayList�����
            st = new StringTokenizer(br.readLine());
            int point[] = new int[2]; // x,y�� ���� �迭
            point[0] = Integer.parseInt(st.nextToken()); // x

            point[1] = Integer.parseInt(st.nextToken()); // y
            input.add(i, point);
        }

        input=quickSort(input);
        for(int i=0;i<input.size();i++) {
            System.out.println(input.get(i)[0]+" "+input.get(i)[1]);
        }
    }

    public static ArrayList<int[]> quickSort(ArrayList<int[]> li) { // ������ �޼ҵ�
        // arr�� start���� end���� ������ �ϴ� �Լ�

        if (li.size() < 2) {// ù ���� �� ������ �׻� �۾ƾ� ��
            return li;
        }
        ArrayList<int[]> left = new ArrayList<>(); // ���� ���� ���� �� list
        ArrayList<int[]> right = new ArrayList<>();// ū ���� ���� �� list

        int[] pivot = li.get(li.size() / 2); // �迭�� ù ��
        li.remove(li.size() / 2);

        for (int i = 0; i < li.size(); i++) {
            if (li.get(i)[0] <= pivot[0]) {
                if (li.get(i)[0]==pivot[0]&&li.get(i)[1] > pivot[1]) {
                    right.add(li.get(i));
                } else {
                    left.add(li.get(i)); // ���� �迭�� ���ڰ� pivot���� Ŭ �� right�� ����
                }
            } else {
                right.add(li.get(i)); // ���� �迭�� ���ڰ� pivot���� ���� �� left�� ����

            }
        }
        left = quickSort(left);
        right = quickSort(right);
        ArrayList<int[]> sortedList = new ArrayList<>();
        sortedList.addAll(left);
        sortedList.add(pivot);
        sortedList.addAll(right);

        return sortedList;

    }

}
