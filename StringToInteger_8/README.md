


# leetcode

Algorithm:

https://leetcode.com/problems/string-to-integer-atoi/

Notice:
	The judgement process will cause overflows if we store the multiply result in a int. we need to store the result
in a double to make sure the waiting check variable not overflow.

For the case of "0-1" should return 0, I make a mistake.
 

Review:

http://edisontus.blogspot.com/2014/01/simple-guide-to-executorservice.html


Tips:

In the android system, especially for the network programing. 

First, I used thread to make connection to the server.
But, because the Android system not allow to send tcp request in the activity main thread in the button click event.
So I use new thread to send request each time.
Yesterday,I noticed the ExecutorService in another android project.

ExecutorServer is almost same as ThreadPoolExecutor, it let me just creat one thread, and execute task for each request.
It is a good idea.

please reference:
https://developer.android.com/reference/java/util/concurrent/ExecutorService
http://edisontus.blogspot.com/2014/01/simple-guide-to-executorservice.html


Share:


https://github.com/EsotericSoftware/kryonet