	int cl[maxn],kc[maxn];
	set<II> q;
void dj(int xp)
{
	//lúc đầu tất cả các đỉnh màu trắng
	cl[xp]=1; // tô đỉnh xuất phát thành màu đen
	kc[xp]=0; // khởi tạo khoảng cách đỉnh xuất phát bằng 0
	q.insert(II(kc[xp],xp)); //cho đỉnh xp vào set
	while(!q.empty()) //khi nào set chưa rỗng
	{
		II t=*q.begin(); //lấy phần tử đầu tiên, phần tử có khoảng cách min
		q.erase(t); //xóa nó khỏi set
		int u=t.sc; // lấy chỉ số đỉnh đó
		for(v ke u)
		{
			l=trong so;
			if(cl[v]==0)
			{
				cl[v]=1;
				kc[v]=kc[u]+l;
				q.insert(II(kc[v],v)); //thêm v vào set
			} else if(kc[v]>kc[u]+l)
			{
				q.erase(II(kc[v],v)); //xóa khỏi set, nếu k có trong set thì set k làm gì cả.
				kc[v]=kc[u]+l;
				q.insert(II(kc[v],v));
			}
		}
	}
}
