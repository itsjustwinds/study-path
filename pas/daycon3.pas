const
        fi='daycon3.inp';
        fo='daycon3.out';
var
        a,b,kq:array[0..101] of longint;
        l:array[0..101,0..101]of longint;
        n,i,j,m,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
                read(f,a[i]);
        for i:=1 to m do
                read(f,b[i]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[0,0]:=0;
        for i:=1 to n do
                for j:=1 to m do
                        if a[i]=b[j] then l[i,j]:=l[i-1,j-1]+1
                        else begin
                        if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]
                        else l[i,j]:=l[i,j-1];
                        end;
        writeln(f,l[n,m]);
        i:=n;j:=m;d:=l[n,m];
        while (i>0) and (j>0) do
                if a[i]=b[j] then
                begin
                        kq[d]:=a[i];
                        dec(d);dec(i);dec(j);
                end
                else begin
                if l[i-1,j]>l[i,j-1] then dec(i)
                else dec(j);
                end;
        for i:=1 to l[n,m] do
                write(f,kq[i],' ');
             {   for i:=1 to n do
                        write(f,a[i],' ');
                        writeln(f);
                for i:=1 to m do
                        write(f,b[i],' '); }
        close(f);
end;
begin
        nhap;
        xuly;
end.
