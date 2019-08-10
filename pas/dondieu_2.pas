const
        fi='dondieu.inp';
        fo='dondieu.out';
var
        a,l,t,kq:array[0..100001] of longint;
        i,j,max,n,k,vt:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1]:=1;
        for i:=1 to n do
        begin
                l[i]:=1;
                for j:=1 to i-1 do
                        if (a[j]<=a[i]) and (l[j]+1>l[i]) then
                        begin
                                l[i]:=l[j]+1;
                                t[i]:=j;
                        end;
        end;
        max:=l[1];
        vt:=1;
        for i:=2 to n do
                if l[i]>max then
                begin
                        max:=l[i];
                        vt:=i;
                end;
        writeln(f,max);
        k:=max;
        repeat
                kq[max]:=a[vt];
                dec(max);
                vt:=t[vt];
        until max=0;
        for i:=1 to k do
                write(f,kq[i],' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.