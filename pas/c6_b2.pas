var
        a:array [1..100,1..100] of integer;
        n,m,i,j:longint;
begin
        write('nhap so hang, so cot la');
        readln(m,n);
        for i:=1 to m do
                for j:=1 to n do
                begin
                        write('nhap A[',i,',',j,']');
                        readln(a[i,j]);
                end;
        write('cac so la boi cua 3 ma khong la boi cua 5 la:');
        for i:=1 to m do
                for j:=1 to n do
                        if (a[i,j] mod 3=0) and (a[i,j] mod 5<>0) then
                                write(a[i,j]:3);
        writeln;
        write('cac so la binh phuong cua so chan la:');
        for i:=1 to m do
                for j:=1 to n do
                        if (trunc(sqrt(a[i,j]))=sqrt(a[i,j])) and (a[i,j] mod 2=0) then
                                write(a[i,j]:4);
        readln
end.