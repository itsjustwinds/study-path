const
        fi='caro.inp';
        fo='caro.out';
var
        a:array[0..1001,0..1001] of string;
        s:string;
        i,j,d,n,m:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=0 to n+1 do
                for j:=0 to m+1 do
                        a[i,j]:='U';
        for i:=1 to n do
        begin
                readln(f,s);
                for j:=1 to m do
                        a[i,j]:=s[j];
        end;
        close(f);
end;
procedure loan(x,y:longint);
begin
        a[x,y]:='U';
        if a[x-1,y-1]<>'U' then loan(x-1,y-1);
        if a[x-1,y]<>'U' then loan(x-1,y);
        if a[x-1,y+1]<>'U' then loan(x-1,y+1);
        if a[x,y-1]<>'U' then loan(x,y-1);
        if a[x,y+1]<>'U' then loan(x,y+1);
        if a[x+1,y-1]<>'U' then loan(x+1,y-1);
        if a[x+1,y]<>'U' then loan(x+1,y);
        if a[x+1,y+1]<>'U' then loan(x+1,y+1);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to n do
                for j:=1 to m do
                        if a[i,j]<>'U' then
                        begin
                                inc(d);
                                loan(i,j);
                        end;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuly;
end.
