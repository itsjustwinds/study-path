const
        fi='abcdefgh.inp';
        fo='abcdefgh.out';
var
        a,l,t,vt:array[ 0..10000] of longint;
        max,i,j,k,n,h,m:longint;
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
        for i:=1 to n do
        begin
                for j:=1 to i-1 do
                        if (a[i]>=a[j]) and (l[j]+1>l[i]) then
                        begin
                                l[i]:=l[j]+1;
                                t[i]:=j;
                        end;
                if l[i]=0 then l[i]:=1;
        end;
        max:=l[1];
        for i:=2 to n do
                if l[i]>max then
                begin
                        max:=l[i];
                        k:=i;
                end;
        h:=max;
        m:=a[k];
        while h<>0 do
        begin
                vt[h]:=m;
                k:=t[k];
                m:=a[k];
                dec(h);
        end;
        for i:=1 to max do
                write(f,vt[i],' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.