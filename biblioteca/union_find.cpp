//based on: https://github.com/pedroteosousa/caderno/blob/master/code/union_find.cpp

ll p[N], w[N];

void init() {
	for (ll i = 0; i < N; i++)
		w[p[i] = i] = 1;
}

ll find(ll x) {
	return p[x] = (x == p[x] ? x : find(p[x]));
}

void join(ll a, ll b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}