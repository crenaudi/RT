#!/bin/sh

TEST_FILE=test_suite_output.txt
EXEC_PATH=./
EXEC_NAME=OMEGART
rm BMP/tickle_me_i_didnt_put_a_filename.bmp
echo -e "Test suite starting. Output will be dumped to test_suite_output.txt\n" ;
touch $TEST_FILE && make $EXEC_PATH ;
i=0
for file in "$@"
do
    echo -e \
     "--------------------------------------------------\n\
STARTING #$i : $file --- time: $(date)\n\
--------------------------------------------------\n"\
     >> test_suite_output.txt;
    $EXEC_PATH/$EXEC_NAME $file >> $TEST_FILE
    echo -e \
     "--------------------------------------------------\n\
ENDING   #$i : $file --- time: $(date)\n\
--------------------------------------------------\n"\
     >> $TEST_FILE
    mv $EXEC_PATH/BMP/tickle_me_i_didnt_put_a_filename.bmp $EXEC_PATH/BMP/$(echo "test_$i.bmp")
    echo "finished test$i"
    i=$((i+1))
done