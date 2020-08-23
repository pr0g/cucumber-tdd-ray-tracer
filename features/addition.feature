# language: en
Feature: Tuple Tests
  Scenario: Adding two tuples
    Given a1 <- tuple(4, -2, 5, 1)
    And   a2 <- tuple(-2, 3, 1, 0)
    Then  a1 + a2 = tuple(2, 1, 6, 1)
