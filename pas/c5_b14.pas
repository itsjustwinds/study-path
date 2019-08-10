var
        a:array [1..100] of longint;
        i,k,n:longint;
begin
        write('nhap so luong phan tu cua a');
        readln(n);
        for i:=1 to n do
        begin
        write('nhap gia tri');
        readln(a[i]);
        end;
        for i:=1 to n do
        write(a[i],' ');
        write('nhap k:');
        readln(k);
        for i:=k to n do
        a[i]:=a[i+1];
        for i:=1 to n do
        write(a[i],' ');
        readln
end.
