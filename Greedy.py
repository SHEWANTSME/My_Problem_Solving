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


# In[17]:


#  곱하기 혹은 더하기
x = input()
ans =int(x[0])
for i in range(1,len(x)):
    if(int(x[i-1]) <=1):
        ans+=int(x[i])
    else:ans*=int(x[i])
print(ans)


# In[41]:


# BOJ 1439 뒤집기
x = input()
if(x.count('1') == len(x) or x.count('0') == len(x)):
    print(0)
    exit(0)
fir = int(x[0])
if(fir==0): sc = 1
else: sc=0

ans1 =0
for i in range(1,len(x)):
    if(int(x[i]) == int(x[i-1])): continue
    else:ans1+=1
ans2=0
idx = -1
#print(sc)
for i in range(1,len(x)):
    if(int(x[i])!=sc): continue
    else:
        idx = i
        break
print(idx)
for i in range(1,len(x)-1):
    if(i >= idx):
        if(int(x[i]) == int(x[i+1])):continue
        #if(int(x[i] == int(x[i+1]))): continue
        else: ans2+=1
print(min(ans1, ans2))
print(ans1 , ans2)


# In[43]:


x = input()
cnt=0
for i in range(len(x)-1):
    if(x[i] != x[i+1]): cnt+=1
print((cnt+1)//2)


# In[ ]:




