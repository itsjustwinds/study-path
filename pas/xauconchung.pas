const
        fi='xauconchung.inp';
        fo='xauconchung.out';
var
        s1,s2,kq:string;
        l:array[0..10001,0..1001]of longint;
        d,i,j,k:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s1);
        read(f,s2);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=0;
        for i:=1 to length(s1) do
                for j:=1 to length(s2) do
                        if s1[i]=s2[j] then l[i,j]:=l[i-1,j-1]+1
                        else begin
                                if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]
                                else l[i,j]:=l[i,j-1];
                        end;
        k:=l[length(s1),length(s2)];
        writeln(f,l[length(s1),length(s2)]);
        i:=length(s1);j:=length(s2);
        while (i>0) and (j>0) do
                if s1[i]=s2[j] then
                begin
                        kq:=s1[i]+kq;
                        dec(i);dec(j);
                end
                else begin
                        if l[i,j]=l[i,j-1] then dec(j)
                        else dec(i);
                end;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.
