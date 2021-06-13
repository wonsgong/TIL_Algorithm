# 최소 신장 트리
> 통신 네트워크 구축에 유용한 자료구조. 
### Spanning Tree  
그래프 내의 모든 정점을 포함하는 트리 -> 그래프의 **최소 연결 부분 그래프**(N개의 정점을 N-1개의 간선으로 연결).  

### Minimum Spanning Tree,MST
Spanning Tree 중 사용된 간선의 가중치 합이 최소인 트리.  
간선의 가중치 합이 최소 / N개의 정점, N-1개의 간선 / 사이클이 포함 X.  
1. [Kruskal MST 알고리즘](https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html).  
2. [Prim MST 알고리즘](https://gmlwjd9405.github.io/2018/08/30/algorithm-prim-mst.html).  

[잘 정리되어있는 블로그 참고](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html).  

## [9372 상근이의여행](./9372_상근이의여행.py)
유니온-파인드를 활용해서 이미 연결되어 있는 국가는 연결할 필요가 없다.  

## [1197 최소스패닝트리](./1197_최소스패닝트리.py)
MST(Minimum Spanning Tree). 스패닝 트리 중 가중치 합이 최소인 트리.  
Prim MST 알고리즘 사용해서 구현.  

## [4386 별자리만들기](./4386_별자리만들기.py)
각각의 점들 간에 거리를 구해서 1197 문제풀듯이 풀면된다.  

## [1774 우주신과의교감](./1774_우주신과의교감.py)
4386 문제 풀듯이 풀면된다.
`c++`에 경우 좌표 계산 시 `float` 범위를 벗어나기 때문에 `double`로 선언해주어야 한다.  