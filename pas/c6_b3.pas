var
        a:array [1..100,1..100] of integer;
        n,m,i,j,dem,max,t:longint;
begin
        write('nhap so hang va so cot:');
        readln(m,n);
        dem:=0;
        t:=0;
        for i:=1 to m do
                for j:=1 to n do
                begin
                        write('nhap A[',i,',',j,']');
                        readln(a[i,j]);
                end;
        write('cac so le cotrong day la:');
        for i:=1 to m do
                for j:=1 to n do
                        if (a[i,j] mod 2<>0) then
                        begin
                                dem:=dem+1;
                                write(a[i,j]:4);
                        end;
                writeln;
        writeln('so luong cac so le la:',dem);
        for i:=1 to m do
                begin
                        max:=a[i,1];
                        for j:=2 to n do
                                if a[i,j]>max then max:=a[i,j];
                        t:=t+max;
                end;
        write('tong cac phan tu lon nhat moi dong la:',t);
        readln
end.



