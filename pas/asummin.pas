const
 fi='ASUMMIN.INP';
 fo='ASUMMIN.OUT';
var
 a,b,vt1,vt2:array[1..100000] of longint;
 m,n,i,j,s,d1,d2,min:longint;
 f:text;
procedure nhap;
 begin
 assign(f,fi);
 reset(f);
 readln(f,m,n);
 for i:=1 to m do
  begin
 read(f,a[i]);
 vt1[i]:=i;
 end;
 readln(f);
 for j:=1 to n do
 begin
 read(f,b[j]);
 vt2[j]:=j;
 end;
 close(f);
 end;
procedure sort1(l,r:longint);
 var u,t,v,x:longint;
  begin
  u:=l;
  v:=r;
  x:=a[(l+r) div 2];
  repeat
  While a[u] < x do inc(u);
  While a[v] > x do dec(v);
  If u<=v then
  begin
  t:=a[u];
  a[u]:=a[v];
  a[v]:=t;
  t:=vt1[u];
  vt1[u]:=vt1[v];
  vt1[v]:=t;
  inc(u);dec(v);
   end;
  until u>v;
  if l<v then sort1(l,v);
  if u<r then sort1(u,r);
  end;
procedure sort2(l,r:longint);
 var u,v,t,x:longint;
 begin
  u:=l;
  v:=r;
  x:=b[(l+r) div 2];
  repeat
  While b[u] > x do inc(u);
  While b[v] < x do dec(v);
  If u<=v then
  begin
  t:=b[u];
  b[u]:=b[v];
  b[v]:=t;
  t:=vt2[u];
  vt2[u]:=vt2[v];
  vt2[v]:=t;
  inc(u);dec(v);
   end;
  until u>v;
  if l<v then sort2(l,v);
  if u<r then sort2(u,r);
  end ;
 procedure xuly;
  begin
   assign(f,fo);
   rewrite(f);
   sort1(1,m);
   sort2(1,n);
   i:=1;j:=1;min:=maxlongint;
   While (i<=m) and (j<=n) do
  begin
   s:=abs(a[i]+b[j]);
   if s<= min then
    begin
     min:=s;
     d1:=vt1[i] ;d2:=vt2[j];
     if min=0 then break;
     end;
    if a[i]+b[j] <0 then inc(i)
    else inc(j);
    end;
    write(f,d1,' ',d2);
    close(f);
    end;
  begin
  nhap;xuly;
 end.
