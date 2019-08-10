const
        fi='bangso.inp';
        fo='bangso.out';
var
        a,l:array[0..17,0..17] of longint;
        n,i,j,m:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                for j:=1 to n do
                read(f,a[i,j]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=a[1,1];
        for i:=2 to n do
        begin
                l[i,1]:=l[i-1,1]+a[i,1];
                l[1,i]:=l[1,i-1]+a[1,i];
        end;
        for i:=2 to n do
                for j:=2 to n do
                if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]+a[i,j]
                else l[i,j]:=l[i,j-1]+a[i,j];
        writeln(f,l[n,n]);
        m:=n;
        while (n<>1) or (m <>1) do
        begin
                write(f,n,',',m,'<-');
                if l[n-1,m]=l[n,m]-a[n,m] then dec(n)
                else dec(m);
        end;
        write(f,n,',',m);
        close(f);
end;
begin
        nhap;
        xuly;
        {for i:=1 to n do
        begin
                for j:=1 to n do
                        write(l[i,j],' ');
                writeln;
        end;

        readln; }
end.
