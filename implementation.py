#!/usr/bin/env python
# coding: utf-8

# In[8]:


# 상하좌우 문제
# 지금은 jupyter에서 문제 풀고 있으니까 걍 input으로 받자
def go(x,y,i):
    if(i>=len(a)):
        print("뀨" , x, y)
        return
    if(a[i]=='R'):
        if(y+1>5 or y+1<1 or x<1 or x>5):
            go(x,y,i+1)
        else:
            y+=1
            #print(x, y)
            go(x,y,i+1)
    if(a[i] == 'U'):
        if(y>5 or y<1 or x-1<1 or x-1>5):
            go(x,y,i+1)
        else:
            x-=1
            #print(x, y)
            go(x,y,i+1)
    if(a[i] == 'L'):
        if(y-1>5 or y-1<1 or x<1 or x>5):
            go(x,y,i+1)
        else:
            y-=1
            #print(x, y)
            go(x,y,i+1)
    if(a[i] == 'D'):
        if(y>5 or y<1 or x+1<1 or x+1>5):
            go(x,y,i+1)
        else:
            x+=1
            #print(x, y)
            go(x,y,i+1)
# 누가봐도 더럽게 풀었다는것을 알 수 있다.
    
    


n = int(input())
a = list(map(str,input().split()))
go(1,1,0)


# In[9]:


n = int(input())
x , y = 1 ,1
plans = input().split() # 아 굳이 list로 안넣어도 잘 되넹 ㅇㅅㅇ..
dx = [0,1,-1,0]
dy = [1,0,0,-1]
move_types = ['R', 'D' , 'U','L']
for i in plans:
    for j in range(4):
        if(i == move_types[j]):
            nx = x + dx[j]
            ny = y + dy[j]
    if nx<1 or ny<1 or nx >n or ny>n:
        continue
    x , y = nx , ny
    
print(x , y)


# In[13]:


# 예제 4-2 시각
cnt=0
x = int(input())
for i in range(x+1):
    for j in range(60):
        for k in range(60):
            if('3' in str(i) + str(j) + str(k)):
                cnt+=1
print(cnt)


# In[47]:


x = input()
y = {'a':1 ,'b':2, 'c':3, 'd':4 , 'e':5 , 'f':6 , 'g':7 , 'h':8}

x1=0
x2=0
for i in y:
    if(i == x[0]):
        x2=y[i]        
        #print(y[i])
xx = int(x2)
yy = int(x[1])
dx = [1,1,-1,-1,-2,-2,2,2]
dy = [2,-2,2,-2,1,-1,1,-1]

ans = 0
for i in range(8):
    nx = xx+dx[i]
    ny = yy+dy[i]
    if(nx>=1 and nx<=8 and ny>=1 and ny<=8):
        ans+=1
    else : continue
print(ans)


# In[49]:


# 답안예시
input_data = input()
row = int(input_data[1])
col = int(ord(input_data[0])) - int(ord('a')) + 1 # 이런게 있는지 몰랐네
steps = [(-2,1) , (-1,-2) , (1,-2) , (2,-1) , (2,1),(1,2),(-1,2),(-2,1)]
res = 0
for i in steps:
    nx = row+ i[0]
    ny = col + i[1]
    if(nx>=1 and nx<=8 and ny>=1 and ny<=8):
        res+=1
        
print(res)
    


# 문제 설명
# 
# 게임 개발
# 문제
# 현민이는 게임 캐릭터가 맵 안에서 움직이는 시스템을 개발 중이다. 캐릭터가 있는 장소는 1 X 1 크기의 정사각형으로 이뤄진 N X M 크기의 직사각형으로, 각각의 칸은 육지 또는 바다이다. 캐릭터는 동서남북 중 한 곳을 바라본다.
# 
# 맵의 각 칸은 (A, B)로 나타낼 수 있고, A는 북쪽으로부터 떨어진 칸의 개수, B는 서쪽으로부터 떨어진 칸의 개수이다. 캐릭터는 상하좌우로 움직일 수 있고, 바다로 되어 있는 공간에는 갈 수 없다. 캐릭터의 움직임을 설정하기 위해 정해 놓은 매뉴얼은 이러하다.
# 
# 현재 위치에서 현재 방향을 기준으로 왼쪽 방향(반시계 방향으로 90도 회전한 방향)부터 차례대로 갈 곳을 정한다.
# 
# 캐릭터의 바로 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽 방향으로 횐전한 다음 왼쪽으로 한 칸을 전진한다. 왼쪽 방향에 가보지 않은 칸이 없다면, 왼쪽 방향으로 회전만 수행하고 1단계로 돌아간다.
# 
# 만약 네 방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸인 경우에는, 바라보는 방향을 유지한 채로 한 칸 뒤로 가고 1단계로 돌아간다. 단, 이때 뒤쪽 방향이 바다인 칸이라 뒤로 갈 수 없는 경우에는 움직임을 멈춘다.
# 
# 현민이는 위 과정을 반복적으로 수행하면서 캐릭터의 움직임에 이상이 있는지 테스트하려고 한다. 메뉴얼에 따라 캐릭터를 이동시킨 뒤에, 캐릭터가 방문한 칸의 수를 출력하는 프로그램을 만드시오.
# 
# 입력
# 첫째 줄에 맵의 세로 크기 N과 가로 크기 M을 공백으로 구분하여 입력한다.
# (3 <= N, M <= 50)
# 
# 둘째 줄에 게임 캐릭터가 있는 칸의 좌표 (A, B)와 바라보는 방햔 d가 각각 서로 공백으로 구분하여 주어진다. 방향 d의 값으로는 다음과 같이 4가지가 존재한다.
# 
# 0 : 북쪽
# 1 : 동쪽
# 2 : 남쪽
# 3 : 서쪽
# 
# 셋째 줄부터 맵이 육지인지 바다인지에 대한 정보가 주어진다. N개의 줄에 맵의 상태가 북쪽부터 남쪽 순서대로, 각 줄의 데이터는 서쪽부터 동쪽 순서대로 주어진다. 맵의 외각은 항상 바다로 되어 있다.
# 
# 0 : 육지
# 1 : 바다
# 처음에 게임 캐릭터가 위치한 칸의 상태는 항상 육지이다.
# 
# 출력
# 첫째 줄에 이동을 마친 후 캐릭터가 방문한 칸의 수를 출력한다.
# 
# 입력 예시
# 4 4
# 1 1 0 // (1, 1)에 북쪽(0)을 바라보고 서 있는 캐릭터
# 1 1 1 1
# 1 0 0 1
# 1 1 0 1
# 1 1 1 1
# 
# 출력 예시
# 3
# 

# In[ ]:





# In[ ]:





# In[57]:


# 게임개발-> Quite hard!
x, y = map(int , input().split())
a,b,ddir = map(int, input().split())
        
visited = [[0]*y for _ in range(x)] # 배열 초기화를 이런식으로..
#print(arr2)
arr = []
for i in range(x):
    arr.append(list(map(int,input().split())))
print(arr)
        
dx = [-1,0,1,0] # 북 동 남 서
dy = [0,1,0,-1]
visited[a][b] = 1
def turn_left():
    global ddir
    ddir -=1
    if(ddir == -1):
        ddir = 3
cnt = 1
turn_time =0
while True: # 이거 재귀적으로 할수있지 않나?
    turn_left()
    nx = a + dx[ddir]
    ny = b + dy[ddir]
    if(visited[nx][ny]==0 and arr[nx][ny]==0): # 노 방문 + 육지
        visited[nx][ny] =1
        a = nx
        b = ny
        cnt+=1
        turn_time = 0
        continue
    else:
        turn_time+=1
    if(turn_time ==4):
        nx = a - dx[ddir]
        ny = b - dy[ddir]
        if(arr[nx][ny]==0):
            a = nx
            b = ny
            turn_time = 0
        else: break
print(cnt)


# In[48]:


int(ord('a')) # C++에선 걍 아스키코드로 변환되는데 python에선 ord붙여야함!


# In[ ]:





# In[ ]:





# In[ ]:




