Const   fi='shhv.inp';
	fo='shhv.out';
Var	a:array [1..12] of longint;
	f,vt:array [0..12] of longint;
	p,n,kq,s:longint;
Procedure sol;
Var	i,j,t,l:longint;
Begin
	f[0]:=1;
	for i:=1 to n do f[i]:=f[i-1]*i;
	for i:=1 to n do vt[i]:=i;
	kq:=1;
	for i:=1 to n do
		Begin
			kq:=kq+(vt[a[i]]-1)*f[n-i];
			for j:=a[i]+1 to n do dec(vt[j]);
		End;
	writeln(kq);
	for i:=1 to n do vt[i]:=i;
	t:=1;
	for i:=1 to n do
		Begin
			for j:=1 to n do
				if (t+j*f[n-i]>p) then
					Begin
						l:=j-1;
						break;
					End;
			t:=t+l*f[n-i];
			a[i]:=vt[l+1];
			for j:=l+1 to n do vt[j]:=vt[j+1];
		End;
	for i:=1 to n do write(a[i],' ');
End;
Begin
	n:=0;
	assign(output,fo); rewrite(output);
	assign(input,fi); reset(input);
	while not eoln do
		Begin
			inc(n);
			read(a[n]);
		End;
	s:=a[n];
	readln(p);
	sol;
End.
