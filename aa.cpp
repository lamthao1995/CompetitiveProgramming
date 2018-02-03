class Solution {
    int tree[];
    public int[] cv(int[] A){
        int cl[] = A.clone();
        HashMap<Integer, Integer> mp = new HashMap();
        Arrays.sort(cl);
        int count = 0;
        for(int i = 0; i < cl.length; i++){
            if(mp.containsKey(cl[i]) == false) count++;
            mp.put(cl[i], count);
        }
        for(int i = 0; i < A.length; i++){
            A[i] =  mp.get(A[i]);
        }
        return A;
    }
    public int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    public void update(int idx, int val){
        while(idx < tree.length){
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    public boolean isIdealPermutation(int[] A) {
        tree = new int[A.length + 1];
        Arrays.fill(tree, 0);
        A = cv(A);
        int gl = 0, lc = 0;
        for(int i = A.length - 1; i >= 0; i--){
            gl += query(A[i] - 1);
            update(A[i], 1);
            if(i != 0 && A[i] < A[i - 1]) lc++;
        }
        return lc == gl;
    }
}
