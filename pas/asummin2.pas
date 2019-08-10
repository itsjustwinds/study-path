const
        fi='asummin.inp';
        fo='asummin.out';
type
        aray=array[1..100001] of int64;
var
        a,a1,b,b1:array[1..100001] of int64;
        g,h,s,t,s1,s2:int64;
        i,j,t2,m,n,t1:longint;
        f:text;
procedure sort(var x:aray;l,r:longint);
var
        u,v,t:longint;
        k:int64;
begin
        u:=l;v:=r;k:=x[l+random(r-l+1)];
        repeat
                while x[u]<k do inc(u);
                while x[v]>k do dec(v);
                if u<=v then
                begin
                        t:=x[u];x[u]:=x[v];x[v]:=t;

                      inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(x,l,v);
        if u<r then sort(x,u,r);
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
        begin
                read(f,a[i]);
                a1[a[i]]:=i;
        end;
        sort(a,1,m);
        readln(f);
        for i:=1 to n do
        begin
                read(f,b[i]);
                b1[b[i]]:=i;
        end;
        sort(b,1,n);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
        begin
                t:=a[i];a[i]:=a[n+1-i];a[n+1-i]:=t;
        end;
        i:=1;j:=1;t1:=a[i];t2:=b[j];s:=abs(a[i]+b[j]);
        while (i<=m) and (j<=n) do
        begin
                s1:=abs(a[i]+b[j+1]);
                s2:=abs(a[i+1]+b[j]);
                if s2>s1 then
                begin
                        inc(j);
                        t2:=b[j];
                        s:=s1;
                end
                else
                begin
                        inc(i);
                        t1:=a[i];
                        s:=s2;
                end;
                if s=0 then break;
                if (i=m) then
                begin
                        inc(j);
                        if s>a[i]+b[j] then
                        begin
                                s:=a[i]+b[j];
                                t2:=b[j];
                        end;
                end;
                if (i<m) and (j=n) then
                begin
                        inc(i);
                        if s>a[i]+b[j] then
                        begin
                                s:=a[i]+b[j];
                                t1:=a[i];
                        end;
                end;
        end;
        write(f,a1[t1],' ',b1[t2]);
        close(f);
end;
begin
        nhap;
        xuly;
end.