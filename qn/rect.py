m, n = map(int, input().split())

a = [[0] * n] * m
for i in range(m):
    a[i] = list(map(int, input().split()))

mx = 0

for i in range(m):
    for j in range(n):
        for u in range(m):
            for v in range(n):
                s = (u - i + 1) * (v - j + 1)
                st = set()
                for ii in range(i, u + 1):
                    for jj in range(j, v + 1):
                        st.add(a[ii][jj])
                if len(st) == s:
                    mx = max(mx, s)

print(mx)
