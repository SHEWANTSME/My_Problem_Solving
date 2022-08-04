#!/usr/bin/env python
# coding: utf-8

# In[12]:


# 예제 3-1은 왜 그리디가 가능한가를 따져볼때
# 500 100 50 10 같이 가지고있는 동전중 큰 단위가 항상 작은 단위의 배수가 되므로
# 작은단위의 동전들을 종합해서 다른 해가 나올 수 없음 (min개수니까)
# BOJ 5585
money = [500,100,50,10,5,1]
x = int(input())
cnt =0
ans =0
change = 1000 - x
while(True):
    print(ans, cnt , change)
    if(change==0 or cnt>5): break
    if(change >= money[cnt]):
        change = change -money[cnt]
        ans+=1
        continue
    if(change<money[cnt]):
        cnt+=1
        continue
#print(ans)


# -----------이렇게 해도 됨

Coin = [500,100,50,10,5,1]

N = int(input())
N = 1000-N

exchange = 0
for i in Coin:
    exchange += N//i
    N=N%i
print(exchange)


# In[ ]:


# 1이 될때까지 

