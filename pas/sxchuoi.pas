const
        fi='sxchuoi.inp';
        fo='sxchuoi.out';
var
        s,s1:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        s1:='';
        while (pos('A',s)<>0) and (pos('B',s)<>0) and (pos('C',s)<>0) do
        begin
                delete(s,pos('A',s),1);
                delete(s,pos('B',s),1);
                delete(s,pos('C',s),1);
                s1:=s1+'CBA';
        end;
         while (pos('B',s)<>0) and (pos('C',s)<>0) do
        begin
                delete(s,pos('B',s),1);
                delete(s,pos('C',s),1);
                s1:=s1+'CB';
        end;
         while (pos('A',s)<>0) and (pos('C',s)<>0) do
        begin
                delete(s,pos('A',s),1);
                delete(s,pos('C',s),1);
                s1:=s1+'CA';
        end;
         while (pos('C',s)<>0)  do
        begin
                delete(s,pos('C',s),1);
                s1:=s1+'C';
        end;
          while (pos('B',s)<>0)  do
        begin
                delete(s,pos('B',s),1);
                s1:=s1+'B';
        end;
        s1:=s1+s;
        write(f,s1);
        close(f);
end;
begin
        nhap;
        xuat;
end.
