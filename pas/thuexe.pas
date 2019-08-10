const
        fi='thuexe.inp';
        fo='thuexe.out';
var
        a,b,c:array[1..100] of longint;
        n,i,j,kq,cuoi,max,dau:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i],b[i],c[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=b[(r+l) div 2];
        repeat
                while b[u]<x do inc(u);
                while b[v]>x do dec(v);
                if u<=v then begin
                        t:=b[u];b[u]:=b[v];b[v]:=t;
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        t:=c[u];c[u]:=c[v];c[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        max:=0;
        for i :=1 to n do
        begin
                kq:=c[i];
                dau:=i;cuoi:=i;
                for j:=i to n do
                begin
                        if b[cuoi]>a[j] then
                        begin
                        if (c[cuoi]<c[j]) and (a[j]>b[cuoi]) then
                        begin
                                kq:=kq-c[cuoi]+c[j];
                                cuoi:=j;
                        end;
                        end
                        else
                        if b[cuoi]<=a[j] then
                        begin
                                kq:=kq+c[j];
                                cuoi:=j;
                        end;
                end;
                if max<kq then max:=kq;
        end;
        writeln(f,max);
      {  for i:=1 to n do
                writeln(f,a[i],' ',b[i],' ',c[i]);    }
        close(f);
end;
begin
        nhap;
        xuly;
end.