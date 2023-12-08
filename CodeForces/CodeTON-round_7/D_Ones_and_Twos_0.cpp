
void solve (void) {
	map<int, int> cnt;
	int n, q; 
	cin >> n >> q;
	vector<int> v(2 * n, 0);
	N = 2 * n;

	for (int i = n; i < 2*n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	// show_vector(v); // DEBUG
	for (int i = n - 1; i > 0; i--) {
		v[i] = v[2 * i] + v[2 * i + 1];
		cnt[v[i]]++;
	}
	// show_vector(v); // DEBUG


	// QUERIES
	for (int i = 0; i < q; i++) {
		show_vector(v); // DEBUG
		int op; 
		cin >> op;

		if (op == 1) {
			int s;
			cin >> s;
			
			if (search_subarray_sum_value_in_segment_tree(v, s)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			int id, val;
			cin >> id >> val;
			id += n - 1;
			v[id] = val;
			while (id > 1) {
				id /= 2;
				v[id] = v[2 * id] + v[2 * id + 1];
			}
		}
	}

}