#include <stdio.h>
#include <iostream>

class Node { // Define the list nodes
public:
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;
    bool isOddList = false;

    Node* reverse_the_LinkedList(Node* current_pointer) {
        Node* prev = nullptr;
        Node* current = current_pointer;
        Node* next;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    Node* find_the_middle() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast && !fast->next) {
            isOddList = true;
        }
        return slow;
    }

public:
    LinkedList() : head(nullptr) {}

    void append(char value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print_list() { // Print the list
        Node* current = head;
        while (current) {
            std::cout << current->data;
            current = current->next;
        }
        std::cout << std::endl;
    }


    bool is_ww(LinkedList l) { // Check if the list is ww
        Node* start = l.head;
        Node* middle = find_the_middle();

        if (isOddList)
            return false;

        while (middle->next != nullptr)
        {
            if (start->data != middle->data)
                return false;

            start = start->next;
            middle = middle->next;
        }
        return true;
    }


    bool is_palindrome() {
        Node* middle = find_the_middle();

        Node* headHalf = head;
        Node* endHalf = reverse_the_LinkedList(middle);

        while (endHalf) {
            if (headHalf->data != endHalf->data) {
                return false;
            }
            headHalf = headHalf->next;
            endHalf = endHalf->next;
        }

        return true;
    }
};


int main() {      //äôòìú äôåð÷öéåú ùáðéðå òì äîçøåæåú ùäúá÷ùðå ìáãå÷ åäåöàú ôìè áäúàí ìúåöàä

    std::string str1 = "ababaababbababaaaababb";
    std::string str2 = "abbabbabbaaaaabbabbabba";
    std::string str3 = "baabaaabbabbabbaabaaabbabbab";
    std::string str4 = "abbabbaabbabba";

    LinkedList List1;
    for (char c : str1) {
        List1.append(c);
    }

    LinkedList List2;
    for (char c : str2) {
        List2.append(c);
    }

    LinkedList List3;
    for (char c : str3) {
        List3.append(c);
    }

    LinkedList List4;
    for (char c : str4) {
        List4.append(c);
    }




    std::cout << std::endl << std::endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 1 - Part one ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl << std::endl;



    bool answer1 = List1.is_ww(List1);              // áãé÷ú îçøåæú øàùåðä
    if (answer1)
    {
        std::cout << " $~~  First string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List1.print_list();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  First string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List1.print_list();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer2 = List2.is_ww(List2);              // áãé÷ú îçøåæú ùðéä 
    if (answer2)
    {
        std::cout << " $~~  Second string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List2.print_list();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Second string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List2.print_list();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer3 = List3.is_ww(List3);              // áãé÷ú îçøåæú ùìéùéú
    if (answer3)
    {
        std::cout << " $~~  Third string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List3.print_list();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Third string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List3.print_list();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    bool answer4 = List4.is_ww(List4);              // áãé÷ú îçøåæú øáéòéú
    if (answer4)
    {
        std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List4.print_list();
        std::cout << " This is A WW type linked list" << std::endl << std::endl;
    }
    else
    {
        std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
        std::cout << " LinkedList: ";
        List4.print_list();
        std::cout << " This is NOT a WW type linked list" << std::endl << std::endl;
    }


    std::cout << std::endl << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Question 2 - Part Two ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl << std::endl;




    std::cout << " $~~  First string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List2.print_list();

    bool answer1b = List1.is_palindrome();              // áãé÷ä ùì äøùéîä î÷åùøú äøàùåðä, äàí äåà îñåâ ôåìéðãøåí
    if (answer1b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    std::cout << " $~~  Second string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List2.print_list();

    bool answer2b = List2.is_palindrome();              // áãé÷ä ùì äøùéîä î÷åùøú äùðéä, äàí äåà îñåâ ôåìéðãøåí 
    if (answer2b)
    {

        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    std::cout << " $~~  Third string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List3.print_list();

    bool answer3b = List3.is_palindrome();              // áãé÷ä ùì äøùéîä î÷åùøú äùìéùéú, äàí äåà îñåâ ôåìéðãøåí
    if (answer3b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    std::cout << " $~~  Fourth string check  ~~$ " << std::endl;
    std::cout << " LinkedList: ";
    List4.print_list();

    bool answer4b = List4.is_palindrome();              // áãé÷ä ùì äøùéîä î÷åùøú äøáéòéú, äàí äåà îñåâ ôåìéðãøåí
    if (answer4b)
    {
        std::cout << " This is a palindrome!" << std::endl << std::endl;
    }
    else
    {
        std::cout << " This is not a palindrome " << std::endl << std::endl;
    }


    return 0;
}
