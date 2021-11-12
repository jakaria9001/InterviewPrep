class Solution:
	# @param A : list of integers
	# @return an integer
	def bulbs(self, a):
	    count = 0
        n = len(a)
        res = 0
        for i in range(n):
            # if the bulb's original state is on and count
            # is even, it is currently on...
            # no need to press this switch
            if (a[i] == 1 and count % 2 == 0):
                continue
     
            # If the bulb's original state is off and count
            # is odd, it is currently on...
            # no need to press this switch
            elif(a[i] == 0 and count % 2 != 0):
                continue
     
            # if the bulb's original state is on and count
            # is odd, it is currently off...
            # Press this switch to on the bulb and increase
            # the count
            elif (a[i] == 1 and count % 2 != 0):
                res += 1
                count += 1
     
            # if the bulb's original state is off and
            # count is even, it is currently off...
            # press this switch to on the bulb and
            # increase the count
            elif (a[i] == 0 and count % 2 == 0):
                res += 1
                count += 1
        return res
