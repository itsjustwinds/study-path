var
        a:array [1..100,1..100] of longint;
        s:array [1..100] of longint;
        m,n,i,j,min,t:longint;
begin
        readln(m,n);
        for i:=1 to m do
                for j:=1 to n do
                begin
                write('nhap phan tu a[',i,',',j,']:');
                readln(a[i,j]);
                end;
        for i:=1 to m do
                begin
                        for j:=1 to n do
                                write(a[i,j]:8);
                        writeln;
                end;
        min:=a[1,1];
        for i:=1 to m do
        begin
                t:=0;
                for j:=1 to n do
                begin
                        t:=t+a[i,j];
                        if a[i,j]<min then min:=a[i,j];
                end;
                s[i]:=t;
        end;
        writeln('so be nhat la:',min);
        for i:=1 to m do
                writeln('tong cua dong ',i,' la:',s[i]);
        readln
end.


