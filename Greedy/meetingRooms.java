// Link: https://www.interviewbit.com/problems/meeting-rooms/

public class Solution {
    public int solve(ArrayList<ArrayList<Integer>> intervals) {
        int len = intervals.size();
        int[] startTime = new int[len];
        int[] endTime = new int[len];
        int index = 0;
        for(ArrayList<Integer> interval: intervals){
            startTime[index] = interval.get(0);
            endTime[index++] = interval.get(1);
        }
        Arrays.sort(startTime);
        Arrays.sort(endTime);
        int i = 0, j = 0;
        int activate = 0, max = 0;
        while(i < len && j < len){
            if(startTime[i] < endTime[j]){
                activate++;
                i++;
            }else{
                activate--;
                j++;
            }
            max = Math.max(max, activate);
        }
        return max;
    }
}
