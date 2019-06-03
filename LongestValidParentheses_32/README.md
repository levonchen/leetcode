
# leetcode

Algorithm:

https://leetcode.com/problems/longest-valid-parentheses/

Review:

http://android-er.blogspot.com/2016/05/android-datagramudp-client-example.html


Tips:

This week, I implemented a requirement to support broadcast udp package in a same segment network.
The requirement as below:

1: In the same segment, there are several Adroid device.
2: Different device has different user info stored.
3: Do some research on one of the android terminal.
4: If the user info found on this device,then show it to the user.
5: If the info not found, broadcast a search info to the segment by using udp.
6: If one of the terminal found the search info on its store. then return the info to the termianl that created the query.
7: If the query initiator received the response during the limited time. show the info.
8: Then show the failed result.

The most important idea is to make the broadcast by setting the last part of the IP to 255. 

Share:


https://www.cnblogs.com/zhujiabin/p/7140492.html