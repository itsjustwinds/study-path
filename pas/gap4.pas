const
        fo='gap9.out';
var
        i:longint;
        f:text;
function xoa1(n:longint):longint;
begin
        xoa1:=n mod 1000;
end;
function xoa2(n:longint):longint;
begin
        xoa2:=((n div 1000)*100)+(n mod 100);
end;
function xoa3(n:longint):longint;
begin
        xoa3:=((n div 100)*10)+(n mod 10);
end;
function xoa4(n:longint):longint;
begin
        xoa4:=n div 10;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1000 to 9999 do
        begin
                if (i=9*xoa1(i)) then
                        writeln(f,i,' ',xoa1(i))
                else
                if (i=9*xoa2(i)) then
                        writeln(f,i,' ',xoa2(i))
                else
                if (i=9*xoa3(i)) then
                        writeln(f,i,' ',xoa3(i))
                else
                if (i=9*xoa4(i)) then
                        writeln(f,i,' ',xoa4(i));
        end;
        close(f);
end;
begin
        xuat;
end.
